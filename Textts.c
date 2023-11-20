#include "Textts.h"

VMWCHAR fullPath1[100];
VMFILE f_read;
vm_sms_launch_data data;

void vm_main(void) {

   VMWCHAR fullPath[100];
   VMWCHAR appName[100];
   VMWCHAR newName[100];
   VMCHAR asciiAppName[100];
   VMCHAR file_name[100];

   VMINT drv;
   VMCHAR f_name[100 + 1];
   VMWCHAR f_wname[100 + 1];
   VMWCHAR *FILE_PATH = 0;

   vm_get_exec_filename(fullPath);
   vm_get_filename(fullPath, appName);
   vm_ucs2_to_ascii(asciiAppName, 100, appName);
   memcpy(file_name, asciiAppName, strlen(asciiAppName) - 3);
   file_name[strlen(asciiAppName) - 3] = '\0';
   strcat(file_name, "txt");

   if ((drv = vm_get_removable_driver()) < 0) {
        drv = vm_get_system_driver();
   }

   sprintf(f_name, "%c:\\%s", drv, file_name);
   vm_ascii_to_ucs2(fullPath1, 100, f_name);

   f_read = vm_file_open(fullPath1, MODE_READ, FALSE);

   if (f_read < 0) {
      vm_file_close(f_read);
      vm_selector_run(0, FILE_PATH, file);
      return;
   } else {
      vm_file_close(f_read);
      read_file_data(fullPath1);
   }
   return;
}

VMINT file(VMWCHAR *FILE_PATH, VMINT wlen) {

    //if (callback != 0){vm_exit_app();}
    //if (wstrlen(FILE_PATH) == 0) {vm_exit_app();}
    vm_wstrcpy(fullPath1, FILE_PATH);
    read_file_data(fullPath1);
}

VMINT read_file_data(VMWSTR path) {

        VMCHAR ascii_data[1999];
        VMWCHAR ucs2_data[2000];
        VMUINT nread;
        void *user_data;

        user_data = vm_malloc(100);

        f_read = vm_file_open(path, MODE_READ, FALSE);

        vm_file_read(f_read, ascii_data, 1999, &nread);
        ascii_data[nread] = '\0';
        vm_file_close(f_read);
        vm_ascii_to_ucs2(ucs2_data, (strlen(ascii_data) + 1) * 2, ascii_data);

        //vm_sim_get_iccid(VM_SMS_SIM_1, mre_sms_callback_function, VMCHAR* iccid, VMINT buff_len, void* user_data); //Get phone no from sim
        //vm_sim_get_iccid_cb callback

	data.addr_type = 0;
	data.addr = (VMWSTR)"*";
	data.subject = 0;
	data.content = ucs2_data;

	vm_sms_launch(&data, sizeof(data));

        vm_free(user_data);
        user_data = NULL;
        return 0;
}

static void mre_sms_callback_function(vm_sms_callback_t *callback_data) {
//static void mre_sms_callback_function(vm_sim_get_iccid_cb *callback_data) {


    if (callback_data->result == 1) {
        if (callback_data->cause == VM_SMS_CAUSE_NO_ERROR) {
            switch (callback_data->action) {
                case VM_SMS_ACTION_NONE:
                    break;
                case VM_SMS_ACTION_READ:
                    mre_msg_content_display();
                    return;
                default:
                    break;
            }
        } else {
        }
    } else {
    }
    return;
}