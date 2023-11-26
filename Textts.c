#include "Textts.h"

VMINT response = 1;
VMINT trigeris = 0;
VMINT trigeris1 = 0;
VMINT trigeris2 = 0;

void vm_main(void) {

   layer_hdl[0] = -1;
   vm_reg_sysevt_callback(handle_sysevt);
   response = vm_selector_run(0, 0, file);
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
            vm_switch_power_saving_mode(turn_off_mode);
            if (trigeris != 0) {vm_exit_app();}
            if (trigeris1 == 1) {trigeris2 = 1;}
            if (response == 0) {trigeris1 = 1;}
            if (trigeris2 == 1) {vm_exit_app();}
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

    response = 1;
    trigeris = 1;
    trigeris1 = 0;
    trigeris2 = 0;

    read_file_data(FILE_PATH);
    return 0;
}

VMINT read_file_data(VMWSTR path) {

        VMCHAR ascii_data[1999];
        VMWCHAR ucs2_data[2000];
        VMUINT nread;
        VMFILE f_read;
        vm_sms_launch_data data;

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
        trigeris = 1;
        return 0;
}

static void mre_sms_callback_function(vm_sms_callback_t *callback_data) {

    if (callback_data->result == 1) {
        if (callback_data->cause == VM_SMS_CAUSE_NO_ERROR) {
            switch (callback_data->action) {
                case VM_SMS_ACTION_NONE:
                    break;
                case VM_SMS_ACTION_READ:
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