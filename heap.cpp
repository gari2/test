int heap[MAX_N], sz = 0;

void push(int x){
    //自分のノードの番号
    int i = sz++;

    while(i > 0){
        //親のノードの番号
        int p = (i-1) 2 ;
        //もう逆転していないならば抜ける
        if(heap[p] <= x)break;
        //親のノードの数字を下ろして、自分は上に
        heap[i] = heap[p];
        i = p;


    }
    heap[i] = x;
    }
    int pop{
        //最小値
        int ret = heap[0];

        //根に持ってくる値
        int x = heap[--sz];

        while(i*2+1 < sz){
            //子同士を比較
            int a = i * 2 + 1, b = i * 2 + 2;
            //もう逆転していないならば終わり
            if(heap[a] >= x)break;

            //子の数字を持ち上げる
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;

        return ret ;


    }

    