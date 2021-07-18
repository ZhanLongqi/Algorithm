# 1057 Stack
## 题目要求
快速实现stack的中间数的读取
## 主要问题
普通算法时间复杂度太高
## 解决方法 
### 线段树
对于本题来说实现过于复杂
### 树状树组
相对容易实现

原理相对较复杂

主要实现方法

```c++
int lowbit(int i){
	return i&(-1*i);
}
```

利用补码特点实现的低位比特获取

```c++
int getsum(int pos){
	int sum=0;
	while(pos>0){
		sum+=tree[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
```

树状树组特点,分解后通过lowbit间隔获取对他做贡献的位

```c++
void update(int pos,int k){
	while(pos<tree.size()){
		tree[pos]+=k;
		pos+=lowbit(pos);
	}
}
```

同理,是上一个方法的逆过程

## 其他问题

树状树组获取的是一个区间的和,所以会导致不止一个区间的和为目标值,所以使用二分法时需要查找最小的符合结果的位置

所以需要对二分法进行改造

```c++
	while(left<right){//需要对位置加紧
		if(getsum(mid)>=target){//当中间值大于目标值时,缩小右区间,由于需要第一个符合的位置,所以等与时,依然缩小右区间
			right=mid;
		}
		else{//当中间值小于目标值时,缩小左边区域,缩小后的left是原本的mid+1,可以保证left值一定大于等于目标值
			left=mid+1;
		}
		mid=(left+right)/2;
	}
	std::cout<<left<<"\n";
```

