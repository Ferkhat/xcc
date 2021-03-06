#pragma once

#include <cc_file_sh.h>
#include <cc_structures.h>

enum t_xcc_ft
{
	xcc_ft_lmd, xcc_ft_xif, xcc_ft_unknown
};

const char* xcc_ft_name[];

class Cxcc_file : public Ccc_file_sh<t_xcc_header>
{
public:
	bool is_valid() const
	{
		const t_xcc_header& h = header();
		int size = get_size();
		return !(sizeof(t_xcc_header) > size || 
			strcmp(h.id, xcc_id) ||
			h.size != size ||
			h.version);
	}

	t_xcc_ft get_ft() const
	{
		return static_cast<t_xcc_ft>(header().type);
	}
};
