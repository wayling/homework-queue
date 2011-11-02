#ifndef __QUEUE_H__
#define __QUEUE_H__
struct stQueue
{
	int iData;
	struct list_head list;
};
void vfnenqueue(void);
void vfndequeue(void);
void vfnprintqueue(void);
void vfnreplace(int);
void vfncheckqueue(void);
#endif
