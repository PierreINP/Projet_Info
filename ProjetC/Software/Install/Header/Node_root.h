#ifndef _NODE_ROOT_H_
#define _NODE_ROOT_H_

#include "./../Header/Node.h"

using namespace std;

class Node_root : public virtual Node {
private:
public:
	Node_root();
	virtual ~Node_root();

//methods
	virtual bool checkStruct();
};

#endif 
