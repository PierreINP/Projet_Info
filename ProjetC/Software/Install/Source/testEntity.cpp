#include "./../Header/Entity.h"

#include <assert.h>
#include <iostream>

using namespace std;

int main(void){
	Entity();
	cout<<Entity.getLabel()<<endl;
	assert(Entity.getLabel() == "Entity");
	Entity2();
	Entity.addSon(Entity2);
}
