void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q=q1;
    q1=q2;
    q2=q;
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()){
        return -1;
    }
    int temp=q1.front();
    q1.pop();
    return temp;
}
