#pragma once


class Daughter;
class Son;

class Parent {

	friend class Son;
	friend class Daughter;

public:
	struct Child {
		int TotalCount;
		int SCount;
		int DCount;
	}
	Child;

private:
	int count = 0;
	struct Child* child = NULL;
	void AddTotal() { child->TotalCount++; }

public:
	Parent() {
		child = (struct Child*)HeapAlloc(
			GetProcessHeap(),
			HEAP_ZERO_MEMORY,
			sizeof(struct Child)
		);
		if (child == NULL) {
			fprintf(stderr, "Cannot alloate child\n");
		}

	}
	~Parent() {};

	int GetTotal() {
		return child->TotalCount;
	}

	struct Child *GetChild() {
		return child;
	}

};


class Son {

public:
	void Add() {
		SCount++;
		AddTotal();
	}

	void SetName(char* Name)
	{
		SName = Name;
	}

	char* SisterName(Daughter* d);
	// This made error.
	//{
	//	return d->DName;
	//}

private:
	friend  Daughter;
	char* SName;
};


class Daughter {

public:
	void Add() {
		child->DCount++;
		AddTotal();
	}

	void SetName(char* Name)
	{
		DName = Name;
	}

	char* BrotherName(Son* s);
	// This made error.
	//{
	//	return s->SName;
	//}

private:
	friend Son;
	char* DName;
};


//
// extern global function for test
//
void Access();
