/***********************************************************************************

    Copyright (C) 2014-2015 Ahmet �zt�rk (aoz_2@yahoo.com)

    This file is part of Lifeograph.

    Lifeograph is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Lifeograph is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Lifeograph.  If not, see <http://www.gnu.org/licenses/>.

***********************************************************************************/


#ifndef LIFEOGRAPH_WIN_APP_WINDOW_HEADER
#define LIFEOGRAPH_WIN_APP_WINDOW_HEADER

#define LIFEOGRAPH_DEVELOPMENT_VERSION


//#define _WIN32_IE 0x0400
#include <commctrl.h>

#include "win_wao.hpp"
#include "win_login.hpp"
#include "win_views.hpp"
#include "helpers.hpp"
#include "settings.hpp"


namespace LIFEO
{

class WinAppWindow
{
    public:
        static constexpr float EDITOR_RATIO = 0.6;
        static constexpr int TOOLBAR_HEIGHT = 35;

                                    WinAppWindow();
                                    ~WinAppWindow();

        int                         run();
        HWND                        get_hwnd() const
        { return m_hwnd; }
        LRESULT                     proc( HWND, UINT, WPARAM, LPARAM );
        BOOL                        proc_toolbar( HWND, UINT, WPARAM, LPARAM );
        void                        handle_create();
        void                        handle_resize( short, short );
        BOOL                        handle_notify( int, LPARAM );

        BOOL                        init_list();
        bool                        select_list_elem( const DiaryElement* );
        bool                        update_list_elem( const DiaryElement* );
        HTREEITEM                   add_list_elem( DiaryElement*, HTREEITEM, bool = false );
        void                        add_chapter_category_to_list( const CategoryChapters*,
                                                                  HTREEITEM );
        DiaryElement*               get_selected_list_elem();

        void                        update_entry_list();

        void                        update_menu();

        void                        fill_monthdaystate( int, int, MONTHDAYSTATE[], int );
        void                        update_calendar();
        void                        update_title();
        void                        update_elem_icon();
        
        void                        handle_calendar_doubleclick( const POINT& );
        
        void                        handle_search_string_changed();
        
        void                        show_today();
        void                        add_todo_entry();
        
        void                        add_chapter( CategoryChapters*, const Date* );

        void                        start_tag_dialog( const Ustring& );

        bool                        authorize();

        bool                        confirm_dismiss_element( const DiaryElement* );
        VOID APIENTRY               display_context_menu( HWND, int, int, int );

        void                        login();
        bool                        finish_editing( bool = true );
        void                        logout( bool );

        void                        show_about();

        bool                        write_backup();

        // AUTO LOGOUT FUNCTIONALITY
        bool                        handle_idle();
        void                        freeze_auto_logout();
        void                        unfreeze_auto_logout();
        void                        update_auto_logout_count_down();
        void                        disable_auto_logout_for_the_session();
        void                        reenable_auto_logout_for_the_session();
        bool                        is_auto_logout_in_use()
        { return( m_auto_logout_status == 0 ); }

        // PANELS AND VIEWS
        static WinAppWindow*        p;
        WinLogin*                   m_login;
        EntryView*                  m_entry_view;
        DiaryView*                  m_diary_view;

        WAO_InputDlg*               m_input_dlg;

    //protected:
        int                         m_seconds_remaining;
        int                         m_auto_logout_status; // reflects the result of all factors
        int                         m_backup_timer_id;

        HWND                        m_hwnd;

        HWND                        m_toolbar;
        HWND                        m_button_about;
        HWND                        m_button_today;
        HWND                        m_button_elem;
        HWND                        m_button_title;
        HWND                        m_button_filter;
        HWND                        m_edit_date;
        HWND                        m_edit_search;

        HWND                        m_calendar;
        HWND                        m_list;
        HWND                        m_list_edit_item;

        HMENU                       m_hmenu;
        HACCEL                      m_haccel;
        
        Date::date_t                m_date_selected;
};

} // end of namespace LIFEO

#endif

