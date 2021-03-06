#pragma once

#include "XCC Mod CreatorDoc.h"

#include "cc_file.h"
#include "xcc_mod.h"

class CXCCModCreatorView : public CListView
{
protected: // create from serialization only
	CXCCModCreatorView();
	DECLARE_DYNCREATE(CXCCModCreatorView)

public:
	CXCCModCreatorDoc* GetDocument()
	{ 
		return (CXCCModCreatorDoc*)m_pDocument; 
	}

	//{{AFX_VIRTUAL(CXCCModCreatorView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL
public:
	int focus() const;
	void clear_game_dir();
	void launch();
	void options();
	void invert_selection();
	void select_all();
	int compare(int id_a, int id_b) const;
	void export();
	int get_free_id() const;
	int remove(string fname);
	void sync();
	void set_category(Cxcc_mod::t_category_type category);
	void sort_list(int i, bool reverse);
	void autosize_colums();
	int insert(string fname);
	virtual ~CXCCModCreatorView();

protected:

// Generated message map functions
protected:
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	//{{AFX_MSG(CXCCModCreatorView)
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditInsert();
	afx_msg void OnUpdateEditInsert(CCmdUI* pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI* pCmdUI);
	afx_msg void OnPopupOpen();
	afx_msg void OnUpdatePopupOpen(CCmdUI* pCmdUI);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPopupExplore();
	afx_msg void OnUpdatePopupExplore(CCmdUI* pCmdUI);
	afx_msg void OnPopupProperties();
	afx_msg void OnUpdatePopupProperties(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
private:
	struct t_map_entry
	{
		string fname;
		t_file_type ft;
		int size;
	};

	static t_map_entry create_map_entry(string fname);

	typedef map<int, t_map_entry> t_map;
	string m_buffer[4];
	int m_buffer_w;
	t_map m_map;
	Cxcc_mod::t_category_type m_category;
	int m_sort_column;
	bool m_sort_reverse;
};
