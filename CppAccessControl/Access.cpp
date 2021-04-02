#include <stdio.h>
#include <Windows.h>
#include "Access.h"

char* Daughter::BrotherName(Son* s)
{
	return s->SName;
}

char* Son::SisterName(Daughter* d)
{
	return d->DName;
}

void Access()
{
	Parent *parent = new Parent();
	Son* son = new Son();
	Daughter* daughter = new Daughter();
	struct Parent::Child* c;

	son->Add();
	daughter->Add();

	son->SetName((char *) "John");
	daughter->SetName((char*) "Mary");

	printf("Total=%d Sister=%s, Brother=%s\n",
		parent->GetTotal(), son->SisterName(daughter), daughter->BrotherName(son));

	c = parent->GetChild();
	printf("P: Total=%d SCount=%d, DCount=%d\n",
		c->TotalCount, c->SCount, c->DCount);

	c = son->GetChild();
	printf("S: Total=%d SCount=%d, DCount=%d\n",
		c->TotalCount, c->SCount, c->DCount);

	c = daughter->GetChild();
	printf("D: Total=%d SCount=%d, DCount=%d\n",
		c->TotalCount, c->SCount, c->DCount);

}
