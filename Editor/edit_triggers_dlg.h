#pragma once

#include "edit_trigger_dlg.h"
#include "list_ctrl_extension.h"
#include "string_conversion.h"
#include "xcc_level.h"

class Cedit_triggers_dlg : public ETSLayoutDialog
{
public:
	void update_controls();
	long get_index(const string& name) const;
	void add_trigger(const string& name);
	void update_trigger(const string& name);
	const string& get_selected_name() const;
	Cedit_triggers_dlg(Cxcc_level& level, bool selection_wanted = false);   // standard constructor

	//{{AFX_DATA(Cedit_triggers_dlg)
	enum { IDD = IDD_EDIT_TRIGGERS_DLG };
	Clist_ctrl_extension	m_list;
	CButton	m_edit_button;
	CButton	m_delete_button;
	CButton	m_ok_button;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(Cedit_triggers_dlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//{{AFX_MSG(Cedit_triggers_dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEdit();
	afx_msg void OnNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Cxcc_level& m_level;
	t_trigger_data& m_trigger_data;
	string m_selected_name;
	const bool m_selection_wanted;
};
