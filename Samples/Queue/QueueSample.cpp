#include <cassert>
#include <Queue.h>

int main()
{  
        zasty::TQueue<int> queue;
        queue.Enqueue(6);
        assert(queue.Dequeue()==6);
}