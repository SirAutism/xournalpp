//
// Created by ulrich on 22.04.19.
//

#include <gdk/gdk.h>
#include <gui/XournalView.h>
#include "TouchDisableGdk.h"

TouchDisableGdk::TouchDisableGdk(GtkWidget* widget) : TouchDisableInterface(), widget(widget)
{
	XOJ_INIT_TYPE(TouchDisableGdk);
}

TouchDisableGdk::~TouchDisableGdk()
{
	XOJ_CHECK_TYPE(TouchDisableGdk);

	XOJ_RELEASE_TYPE(TouchDisableGdk);
}

void TouchDisableGdk::init()
{
	XOJ_CHECK_TYPE(TouchDisableGdk);
}

void TouchDisableGdk::enableTouch()
{
	XOJ_CHECK_TYPE(TouchDisableGdk);

#ifdef DEBUG_INPUT
	g_message("Enable touch");
#endif

	gtk_grab_remove(this->widget);
	gdk_pointer_ungrab(GDK_CURRENT_TIME);
}

void TouchDisableGdk::disableTouch()
{
	XOJ_CHECK_TYPE(TouchDisableGdk);

#ifdef DEBUG_INPUT
	g_message("Disable touch using GDK grabs");
#endif
	GdkWindow* window = gtk_widget_get_window(this->widget);

	/**
	 * See the following link if window dragging by double clicks on empty widget space occurs
	 * https://www.reddit.com/r/kde/comments/aaeo91
	 */
	gdk_pointer_grab(window, false, GDK_TOUCH_MASK, nullptr, nullptr, GDK_CURRENT_TIME);
	gtk_grab_add(this->widget);
}

