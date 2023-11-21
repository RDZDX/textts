#include "Textts.h"

VMWCHAR fullPath1[100];
//VMFILE f_read;
//vm_sms_launch_data data;
//VMUINT8 *buffer;
VMINT response = 1;
VMINT trigeris = 0;
VMINT ilgis = 1;


void vm_main(void) {

   //VMWCHAR fullPath1[100];
   layer_hdl[0] = -1;
   vm_reg_sysevt_callback(handle_sysevt);

   VMWCHAR fullPath[100];
   VMWCHAR appName[100];
   VMWCHAR newName[100];
   VMCHAR asciiAppName[100];
   VMCHAR file_name[100];

   VMINT drv;
   VMCHAR f_name[100 + 1];
   VMWCHAR f_wname[100 + 1];
   VMWCHAR *FILE_PATH = 0;
   //VMINT response;
   VMFILE f_read;

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
      response = vm_selector_run(0, FILE_PATH, file);
      //trigeris = 1;
      //return;
      if (response == 0) {ilgis = 0;}
   } else {
      vm_file_close(f_read);
      read_file_data(fullPath1);
   }
   //if (response != 0){vm_vibrator_once();}
   //vm_vibrator_once();
   //vm_exit_app();
   //return;
   //if (response == 0) {vm_vibrator_once();}
   //if (ilgis != 1) {vm_vibrator_once();}
}

void handle_sysevt(VMINT message, VMINT param) {

    VMUINT8 *buffer;

    switch (message) {
        case VM_MSG_CREATE:
        case VM_MSG_ACTIVE:
            layer_hdl[0] =
                vm_graphic_create_layer(0, 0, vm_graphic_get_screen_width(),
                                        vm_graphic_get_screen_height(), -1);
            vm_graphic_set_clip(0, 0, vm_graphic_get_screen_width(),
                                vm_graphic_get_screen_height());
            buffer = vm_graphic_get_layer_buffer(layer_hdl[0]);
            vm_switch_power_saving_mode(turn_off_mode);
            break;

        case VM_MSG_PAINT:
            //vm_switch_power_saving_mode(turn_off_mode);
            //if (trigeris != 0 || response == 0) {vm_exit_app();}
            if (trigeris != 0) {vm_exit_app();}
            else {mre_draw_black_rectangle();}
            break;

        case VM_MSG_INACTIVE:

            vm_switch_power_saving_mode(turn_on_mode);
            if (layer_hdl[0] != -1) vm_graphic_delete_layer(layer_hdl[0]);
            break;

        case VM_MSG_QUIT:
            if (layer_hdl[0] != -1) vm_graphic_delete_layer(layer_hdl[0]);
            break;
    }
}

static VMINT file(VMWCHAR *FILE_PATH, VMINT wlen) {

    if (wlen == 0) {
       vm_vibrator_once();
       return 0;
    }
    //trigeris = 0;
    ilgis = wlen;
    response = 1;
    vm_wstrcpy(fullPath1, FILE_PATH);
    read_file_data(fullPath1);
    //vm_exit_app();
    //vm_vibrator_once();
    return 0;
}

VMINT read_file_data(VMWSTR path) {

        VMCHAR ascii_data[1999];
        VMWCHAR ucs2_data[2000];
        VMUINT nread;
        VMFILE f_read;
        vm_sms_launch_data data;
        //void *user_data;

        //user_data = vm_malloc(100);

        //if (response == 0) {vm_vibrator_once();}

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

        //vm_vibrator_once();
        //vm_exit_app();
        //vm_free(user_data);
        //user_data = NULL;
        //wstrcpy(fullPath1, "");
        trigeris = 1;
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

void mre_draw_black_rectangle(void) {

    VMUINT8 *buffer;

    buffer = vm_graphic_get_layer_buffer(layer_hdl[0]);
    vm_graphic_fill_rect(buffer, 0, 0, vm_graphic_get_screen_width(),
                         vm_graphic_get_screen_height(), VM_COLOR_BLACK,
                         VM_COLOR_BLACK);
    vm_graphic_flush_layer(layer_hdl, 1);
}
