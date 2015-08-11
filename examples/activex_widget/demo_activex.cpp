
#include "demo_activex.h"

#include "base/path_service.h"
#include "ui/views/controls/activex/mediaplay_view.h"
#include "ui/views/controls/activex/flash_view.h"
#include "ui/views/controls/button/text_button.h"
#include "ui/views/layout/grid_layout.h"
#include "ui/views/widget/widget.h"

#include "demo_main.h"

DemoActiveX::DemoActiveX() : view_created_(false),
flash_view_(NULL), media_player_(NULL),
play_flash_(NULL), play_wmv_(NULL),
create_flash_popup_(NULL) {}

DemoActiveX::~DemoActiveX() {}

std::wstring DemoActiveX::GetTitle()
{
    return std::wstring(L"ActiveX");
}

void DemoActiveX::InitView(views::View* container)
{
    views::GridLayout* layout = new views::GridLayout(container);
    container->SetLayoutManager(layout);

    views::ColumnSet* column_set = layout->AddColumnSet(0);
    column_set->AddColumn(views::GridLayout::FILL, views::GridLayout::FILL,
        1.0f, views::GridLayout::USE_PREF, 0, 0);
    column_set->AddColumn(views::GridLayout::FILL, views::GridLayout::FILL,
        1.0f, views::GridLayout::USE_PREF, 0, 0);
    views::ColumnSet* column_set_1 = layout->AddColumnSet(1);
    column_set_1->AddColumn(views::GridLayout::FILL, views::GridLayout::FILL,
        1.0f, views::GridLayout::USE_PREF, 0, 0);
    column_set_1->AddColumn(views::GridLayout::FILL, views::GridLayout::FILL,
        1.0f, views::GridLayout::USE_PREF, 0, 0);
    column_set_1->AddColumn(views::GridLayout::FILL, views::GridLayout::FILL,
        1.0f, views::GridLayout::USE_PREF, 0, 0);
	layout->StartRow(1.0f, 0);  

	media_player_ = new views::MediaPlayerView();
	layout->AddView(media_player_); 
	flash_view_ = new views::FlashView();
	layout->AddView(flash_view_);


    play_flash_ = new views::NativeTextButton(this, L"����Flash");
    play_wmv_ = new views::NativeTextButton(this, L"����WMV");
    create_flash_popup_ = new views::NativeTextButton(this, L"����͸��Flash����");
    layout->StartRow(0.0f, 1);
    layout->AddView(play_flash_);
    layout->AddView(play_wmv_);
    layout->AddView(create_flash_popup_);
}

void DemoActiveX::ButtonPressed(views::Button* sender,
                                const ui::Event& event)
{
    if(play_flash_ == sender)
    {
		base::FilePath path;
		PathService::Get(base::DIR_EXE, &path);
		base::FilePath path_flash = path.Append(L"res/Construction.swf");
        flash_view_->Play(path_flash.value());
    }
    else if(play_wmv_ == sender)
    { 
		base::FilePath path;		
        PathService::Get(base::DIR_EXE, &path);		
		base::FilePath path_wmv = path.Append(L"res/FullScreen.wmv");	
        media_player_->Play( path_wmv.value() );
    } 
    else if(create_flash_popup_ == sender)
    {
        views::Widget* window = new views::Widget();
        views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
        params.transparent = true;
        params.bounds = gfx::Rect(0, 0, 400, 400);
        params.transparent = true;
        window->Init(params);
        base::FilePath path;
        PathService::Get(base::DIR_EXE, &path);
        base::FilePath path_flash = path.Append(L"res/Construction.swf");
        views::FlashView* flash_view = new views::FlashView();
        window->SetContentsView(flash_view);
        window->Show();
        flash_view->Play(path_flash.value());
    }
}