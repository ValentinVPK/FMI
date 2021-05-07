#pragma once

class Counter {
protected:
	int value;
	unsigned steps;
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);
	void increment();
	int getTotal() const;
	unsigned getStep() const;
};
