--- third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp.orig	2014-05-30 12:30:59.914178491 -0500
+++ third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp	2014-05-30 12:39:42.381145107 -0500
@@ -19,6 +19,165 @@
 #include "../../include/javascript/color.h"
 #include "../../include/javascript/JS_Runtime.h"
 
+
+#include <math.h>
+
+/* big enough to handle %.20f conversion of 1e308 */
+#define	NDIG		350
+
+#define msign ((unsigned short)0x7fff)
+#define mexp ((unsigned short)0x7ff0)
+
+static double L = 4503599627370496.0E0;		/* 2**52 */
+
+static int ecvt_init = 0;
+
+#define isNAN(x) ((x) != (x))
+
+static double
+ecvt_copysign(double x, double y)
+{
+    unsigned short *px, *py;
+
+    px = (unsigned short *)&x;
+    py = (unsigned short *)&y;
+    *px = (*px & msign) | (*py & ~msign);
+    return (x);
+}
+
+static double
+ecvt_rint(double x)
+{
+    double s, t, one;
+
+    one = 1.0;
+
+    if (ecvt_init == 0) {
+	int i;
+	L = 1.0;
+	for (i = 52; i != 0; i--)
+	    L *= 2.0;
+	ecvt_init = 1;
+    }
+    if (isNAN(x))
+	return (x);
+    if (ecvt_copysign(x, one) >= L)		/* already an integer */
+	return (x);
+    s = ecvt_copysign(L, x);
+    t = x + s;				/* x+s rounded to integer */
+    return (t - s);
+}
+
+static char *
+cvt(double arg, int ndigits, int *decptp, int *signp, int eflag)
+{
+    int decpt;
+    double fi, fj;
+    char *p, *p1;
+    static char buf[NDIG] = { 0 };
+
+    if (ndigits < 0)
+	ndigits = 0;
+    if (ndigits >= NDIG - 1)
+	ndigits = NDIG - 2;
+
+    decpt = 0;
+    *signp = 0;
+    p = &buf[0];
+
+    if (arg == 0) {
+	*decptp = 0;
+	while (p < &buf[ndigits])
+	    *p++ = '0';
+	*p = '\0';
+	return (buf);
+    } else if (arg < 0) {
+	*signp = 1;
+	arg = -arg;
+    }
+
+    arg = modf(arg, &fi);
+    p1 = &buf[NDIG];
+
+    /* Do integer part */
+
+    if (fi != 0) {
+	while (fi != 0) {
+	    fj = modf(fi/10, &fi);
+#if 0
+	    *--p1 = (int)((fj + 0.03) * 10) + '0';
+#else
+	    *--p1 = (int)ecvt_rint(fj * 10) + '0';
+#endif
+	    decpt++;
+	}
+	while (p1 < &buf[NDIG])
+	    *p++ = *p1++;
+    } else if (arg > 0) {
+	while ((fj = arg*10) < 1) {
+	    arg = fj;
+	    decpt--;
+	}
+    }
+    *decptp = decpt;
+
+    /* Do the fractional part.
+     * p pts to where fraction should be concatenated.
+     * p1 is how far conversion must go to.
+     */
+    p1 = &buf[ndigits];
+    if (eflag == 0) {
+	/* fcvt must provide ndigits after decimal pt */
+	p1 += decpt;
+	/* if decpt was negative, we might be done for fcvt */
+	if (p1 < &buf[0]) {
+	    buf[0] = '\0';
+	    return (buf);
+	}
+    }
+
+    while (p <= p1 && p < &buf[NDIG]) {
+	arg *= 10;
+	arg = modf(arg, &fj);
+	*p++ = (int)fj + '0';
+    }
+
+    /* If we converted all the way to the end of the buf, don't mess with
+     * rounding since there's nothing significant out here anyway.
+     */
+    if (p1 >= &buf[NDIG]) {
+	buf[NDIG-1] = '\0';
+	return (buf);
+    }
+
+    /* Round by adding 5 to last digit and propagating carries. */
+    p = p1;
+    *p1 += 5;
+    while (*p1 > '9') {
+	*p1 = '0';
+	if (p1 > buf) {
+	    ++*--p1;
+	} else {
+	    *p1 = '1';
+	    (*decptp)++;
+	    if (eflag == 0) {
+		if (p > buf)
+		    *p = '0';
+		p++;
+	    }
+	}
+    }
+    *p = '\0';
+    return (buf);
+}
+
+char *
+fcvt(double arg, int ndigits, int *decptp, int *signp)
+{
+    return (cvt(arg, ndigits, decptp, signp, 0));
+}
+
+
 static v8::Isolate* GetIsolate(IFXJS_Context* cc)
 {
 	CJS_Context* pContext = (CJS_Context *)cc;
