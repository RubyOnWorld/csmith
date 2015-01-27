// -*- mode: C++ -*-
//
// Copyright (c) 2007, 2008, 2009, 2010, 2011 The University of Utah
// All rights reserved.
//
// This file is part of `csmith', a random generator of C programs.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef VECTOR_FILTER_H
#define VECTOR_FILTER_H

#include <vector>
#include "Filter.h"

class DistributionTable;

// Filter out elements from the vector, i.e., elements in the vector
// is invalid.
#define FILTER_OUT 0
// Elements in the vector are valid
#define NOT_FILTER_OUT 1

class VectorFilter : public Filter
{
public:
	VectorFilter(void);
	VectorFilter(DistributionTable *table);
	explicit VectorFilter(std::vector<unsigned int> &vs, int flag = FILTER_OUT);

	VectorFilter& add(unsigned int item);

	int get_max_prob(void) const;

	int lookup(int v) const;

	virtual ~VectorFilter(void);

	virtual bool filter(int v) const;
private:
	std::vector<unsigned int> vs_;

	DistributionTable *ptable;

	int flag_;
};

#endif // VECTOR_FILTER_H
