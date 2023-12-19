#pragma once

#include <furi.h>
#include <furi_hal.h>
#include <input/input.h>

#include "lib/toolbox/path.h"
#include <notification/notification.h>
#include <notification/notification_messages.h>
#include <string.h>

#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/view_stack.h>
#include <gui/scene_manager.h>
#include <gui/modules/text_input.h>
#include <gui/modules/popup.h>
#include <gui/modules/widget.h>
#include <gui/modules/loading.h>

#include <dialogs/dialogs.h>

#include <lib/subghz/protocols/base.h>
#include <lib/subghz/transmitter.h>
#include <lib/subghz/receiver.h>
#include <lib/subghz/environment.h>
#include <notification/notification.h>
#include <notification/notification_messages.h>

#include <lib/toolbox/stream/stream.h>

#include "shapshup.h"
#include "scenes/shapshup_scene.h"
#include "views/shapshup_main_view.h"
#include "helpers/shapshup_files.h"

/**
 * @brief max size of text field
 * 
 */
#define SHAPSHUP_TEXT_STORE_SIZE 255
/**
 * @brief max size of filename
 * 
 */
#define SHAPSHUP_MAX_LEN_NAME 64
/**
 * @brief default directory to show
 * 
 */
#define SHAPSHUP_PATH EXT_PATH("subghz")
/**
 * @brief filename extension to show
 * 
 */
#define SHAPSHUP_FILE_EXT ".sub"

/**
 * @brief used for DEBUG purpose
 * 
 */
//#define SHAPSHUP_FAST_TRACK false

/**
 * @brief view mode
 * 
 */
typedef enum {
    ShapShupViewNone,
    ShapShupViewMain,
    ShapShupViewTextInput,
    ShapShupViewDialogEx,
    ShapShupViewPopup,
    ShapShupViewLoading,
    ShapShupViewWidget,
    ShapShupViewStack,
} ShapShupView;

/**
 * @brief main state of app
 * 
 */
struct ShapShupState {
    // GUI elements
    NotificationApp *notifications;
    Gui *gui;
    ViewDispatcher *view_dispatcher;
    ViewStack *view_stack;
    TextInput *text_input;
    Popup *popup;
    Widget *widget;
    DialogsApp *dialogs;
    Loading *loading;

    char text_store[SHAPSHUP_MAX_LEN_NAME];
    FuriString *file_path;

    ShapShupMainView *view_main; /** View main, default view*/
    ShapShupView current_view; /** @enum ShapShupView for track enums */
    SceneManager *scene_manager; /** Scene manager*/
    Storage *storage; /** Storage pointer */
};

/**
 * @brief shapshup_show_loading_popup
 * 
 * @param context 
 * @param show 
 */
void shapshup_show_loading_popup(void *context, bool show);

/**
 * @brief shapshup_text_input_callback
 * 
 * @param context 
 */
void shapshup_text_input_callback(void *context);

/**
 * @brief shapshup_popup_closed_callback
 * 
 * @param context 
 */
void shapshup_popup_closed_callback(void *context);
