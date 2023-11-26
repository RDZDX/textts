#ifndef _VRE_APP_WIZARDTEMPLATE_
#define	_VRE_APP_WIZARDTEMPLATE_

#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmsms.h"
#include "string.h"

VMINT		layer_hdl[1];				////layer handle array.

void handle_sysevt(VMINT message, VMINT param);
static VMINT file(VMWCHAR *FILE_PATH, VMINT wlen);
VMINT read_file_data(VMWSTR path);
static void mre_sms_callback_function(vm_sms_callback_t *callback_data);

#endif

