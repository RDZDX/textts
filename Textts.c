#include "Textts.h"

VMWSTR myPath;
//VMWCHAR path[101];

VMCHAR file_name[100] = "newx.txt";
VMFILE f_read;

VMWCHAR x1[101];

vm_sms_launch_data data;
//data.addr_type = 0;
//data.addr = x1;
//data.sim = 1;
//data.subject = 0;

void vm_main(void) {

	//vm_sms_launch_data data;
	//VMWCHAR x1[101];
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

	//vm_sms_launch(&data, sizeof(data));
        checkFileExist();
        //read_file_data(myPath);
}


VMINT file(VMWCHAR *FILE_PATH, VMINT wlen) {

    myPath = vm_realloc(myPath, (wlen + 1) * 2);
    vm_wstrcpy(myPath, FILE_PATH);
    //f_read = vm_file_open(path, MODE_READ, FALSE);
    read_file_data(myPath);
    return 0;
}

VMINT read_file_data(VMWSTR path) {

        VMCHAR ascii_data[1999];
        VMWCHAR ucs2_data[2000];
        VMUINT nread;
        f_read = vm_file_open(myPath, MODE_READ, FALSE);
        vm_file_read(f_read, ascii_data, 1999, &nread);
        ascii_data[nread] = '\0';
        vm_file_close(f_read);
        vm_ascii_to_ucs2(ucs2_data, (strlen(ascii_data) + 1) * 2, ascii_data);

	data.addr_type = 0;
	data.addr = x1;
	//data.sim = 1;
	data.subject = 0;
	//data.content = s1;

	data.content = ucs2_data;

	vm_sms_launch(&data, sizeof(data));
        return 0;
}

void checkFileExist(void) {

    VMINT drv;
    VMCHAR f_name[100 + 1];
    VMWCHAR f_wname[100 + 1];
    VMFILE f_read;
    VMWCHAR *FILE_PATH = 0;
    int size = 0;

    if ((drv = vm_get_removable_driver()) < 0) {
        drv = vm_get_system_driver();
    }

    sprintf(f_name, "%c:\\%s", drv, file_name);
    vm_ascii_to_ucs2(f_wname, 100, f_name);
    f_read = vm_file_open(f_wname, MODE_READ, FALSE);

    if (f_read < 0) {
        vm_file_close(f_read);
        vm_selector_run(0, FILE_PATH, file);
    } else {
        size = (strlen(f_name) + 1) * 2;
        myPath = vm_malloc(size);
        vm_wstrcpy(myPath, f_wname);
        read_file_data(myPath);
    }
}