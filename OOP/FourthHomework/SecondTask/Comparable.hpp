#pragma once

class Comparable {
public:
	virtual bool operator==(const Comparable* rhs)const = 0;
	virtual bool operator!=(const Comparable* rhs)const = 0;

	virtual ~Comparable() {};
};
