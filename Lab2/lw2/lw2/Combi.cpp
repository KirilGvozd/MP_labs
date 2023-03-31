#include "stdafx.h"
#include "Combi.h"
#include <algorithm>

namespace combi
{
	subset::subset(short n)
	{
		this->n = n;				///кол элементов исходного массива
		this->sset = new short[n];	///массив индексов текущего подмножества 
		this->reset();
	};

	void  subset::reset()	///сбросить генератор 
	{
		this->sn = 0;		///кол-во элементов текущего подмножества 
		this->mask = 0;		///бит маска
	};

	short subset::getfirst()		///сформ массив индексов по бит маске
	{
		__int64 buf = this->mask;
		this->sn = 0;
		for (short i = 0; i < n; i++)
		{
			if (buf & 0x1)
			{
				this->sset[this->sn++] = i;///массив индексов текущего подмножества 
			}
			buf >>= 1;
		}
		return this->sn;///кол-во эл-тов текущего подмножества 
	};

	short subset::getnext()			///++маска и сформ массив индексов
	{
		int rc = -1;
		this->sn = 0;
		if (++this->mask < this->count())
		{
			rc = getfirst();
		}
		return rc;
	};

	short subset::ntx(short i)	///i-й эл-т массива индексов
	{
		return  this->sset[i];
	};

	unsigned __int64 subset::count()	///общее кол-во подмн-в
	{
		return (unsigned __int64)(1 << this->n);
	};

};
