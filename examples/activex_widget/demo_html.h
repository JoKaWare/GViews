
#ifndef __demo_html_h__
#define __demo_html_h__

#pragma once

#include "ui/views/controls/button/button.h"
#include "ui/views/view.h"


namespace views
{
	class View;
    class HtmlView;
    class NativeTextButton;
    class Textfield;
}

class DemoHtml : public views::View, public views::ButtonListener
{
public:
    explicit DemoHtml();
    virtual ~DemoHtml();
	virtual void ViewHierarchyChanged(bool is_add,
		View* parent,
		View* child) OVERRIDE 
	{
		View::ViewHierarchyChanged(is_add, parent, child);
		// We're not using child == this because a Widget may not be
		// available when this is added to the hierarchy.
		if (is_add && GetWidget() && !view_created_) {
			view_created_ = true;
			InitView(this);
		}
	}
	bool view_created_;
    // Overridden from DemoBase:
    virtual std::wstring GetTitle();
    virtual void InitView(views::View* container);

    // Overridden from views::ButtonListener:
	virtual void ButtonPressed(views::Button* sender,
        const ui::Event& event);
	 
private:
    views::HtmlView* html_view_;
    views::Textfield* html_;
    views::NativeTextButton* button_;

    DISALLOW_COPY_AND_ASSIGN(DemoHtml);
};

#endif //__demo_html_h__