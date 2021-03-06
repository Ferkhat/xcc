#pragma once

#include "ListCtrlEx.h"
#include "csf_file.h"
#include "resource.h"

class CXSTE_dlg : public ETSLayoutDialog
{
public:
	void open(const string& name);
	void create_cat_map();
	int get_cat_id(const string& name) const;
	void set_map_entry(int id, const string& name);
	void sort_list(int i, bool reverse);
	int get_current_index();
	int get_free_id();
	int insert(int id);
	void check_selection();
	int compare(int id_a, int id_b) const;
	CXSTE_dlg(t_game game, CWnd* pParent = NULL);   // standard constructor

	//{{AFX_DATA(CXSTE_dlg)
	enum { IDD = IDD_XSTE };
	CListCtrlEx	m_cat_list;
	CButton	m_insert;
	CButton	m_edit;
	CButton	m_delete;
	CListCtrlEx	m_list;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CXSTE_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
protected:
	//{{AFX_MSG(CXSTE_dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnEdit();
	afx_msg void OnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnInsert();
	afx_msg void OnDelete();
	afx_msg void OnEndlabeleditList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedCatList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	struct t_map_entry
	{
		const Ccsf_file::t_map::value_type* i;
		int cat_id;
	};

	using t_cat_map = map<int, string>;
	using t_map = map<int, t_map_entry>;
	using t_reverse_cat_map = map<string, int>;

	t_game m_game;
	string m_fname;
	t_cat_map m_cat_map;
	Ccsf_file m_f;
	t_map m_map;
	t_reverse_cat_map m_reverse_cat_map;
	int m_sort_column;
	bool m_sort_reverse;
};
