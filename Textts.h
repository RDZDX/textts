#ifndef _VRE_APP_WIZARDTEMPLATE_
#define	_VRE_APP_WIZARDTEMPLATE_

#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "ResID.h"
#include "vm4res.h"
#include "vmsms.h"

#include <string.h>
#include "stdint.h"

VMINT file(VMWCHAR *FILE_PATH, VMINT wlen);
VMINT read_file_data(VMWSTR path);
void checkFileExist(void);

#endif

