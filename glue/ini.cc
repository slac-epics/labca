/* $Id: ini.cc,v 1.5 2003/12/31 07:58:17 till Exp $ */

/* xlabcaglue library initializer */

#include <cadef.h>
#include <ezca.h>
#include <mex.h>

#define DEF_TIMEOUT 0.2
#define DEF_RETRIES 20

static int
ezlibinit()
{
/* don't print to stderr because that
 * doesn't go to scilab's main window...
 */
mexPrintf((char*)"Initializing labCA Release '$Name:  $'...\n");
mexPrintf((char*)"Author: Till Straumann <strauman@slac.stanford.edu>\n");
ezcaAutoErrorMessageOff();
mexPrintf((char*)"Polling interval is %.2fs; max. timeout: %.2fs\n",
				DEF_TIMEOUT, DEF_RETRIES*DEF_TIMEOUT);
ezcaSetTimeout((float)DEF_TIMEOUT);
ezcaSetRetryCount(DEF_RETRIES);
return 0;
}

static int dummy = ezlibinit();
