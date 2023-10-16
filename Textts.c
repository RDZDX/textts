#include "Textts.h"

VMWSTR myPath;
VMFILE f_read;
vm_sms_launch_data data;

void vm_main(void) {

    VMCHAR file_name[100] = "Textts.txt";
    //vm_get_exec_filename(VMWSTR filename);
    VMINT drv;
    VMCHAR f_name[100 + 1];
    VMWCHAR f_wname[100 + 1];
    VMWCHAR *FILE_PATH = 0;

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
        vm_file_close(f_read);
        myPath = vm_malloc((strlen(f_name) + 1) * 2);
        vm_wstrcpy(myPath, f_wname);
        read_file_data(myPath);
    }
    vm_free(myPath);
}

VMINT file(VMWCHAR *FILE_PATH, VMINT wlen) {

    myPath = vm_realloc(myPath, (wlen + 1) * 2);
    vm_wstrcpy(myPath, FILE_PATH);
    read_file_data(myPath);
    return 0;
}

VMINT read_file_data(VMWSTR path) {

        VMCHAR ascii_data[1999];
        VMWCHAR ucs2_data[2000];
        VMUINT nread;

        f_read = vm_file_open(path, MODE_READ, FALSE);

        vm_file_read(f_read, ascii_data, 1999, &nread);
        ascii_data[nread] = '\0';
        vm_file_close(f_read);
        vm_ascii_to_ucs2(ucs2_data, (strlen(ascii_data) + 1) * 2, ascii_data);

	data.addr_type = 0;
	data.addr = (VMWSTR)"*";
	data.subject = 0;
	data.content = ucs2_data;

	vm_sms_launch(&data, sizeof(data));

        return 0;
}