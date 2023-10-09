#include "Textts.h"

void vm_main(void) {

	vm_sms_launch_data data;
	VMWCHAR x1[101];
	VMCHAR x2[100] = "+370000000000";
	VMWCHAR s1[101];
	VMCHAR s2[100] = "Hello World!";

        vm_ascii_to_ucs2(x1, (strlen(x2) + 1) * 2, x2);
        vm_ascii_to_ucs2(s1, (strlen(s2) + 1) * 2, s2);

	data.addr_type = 0;
	data.addr = x1;
	//data.sim = 1;
	data.subject = 0;
	data.content = s1;

	vm_sms_launch(&data, sizeof(data));
}