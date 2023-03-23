#这里是基于常规方法（递归法）实现汉诺塔问题，可能并不高效
#思路解析：在演示过程中发现：1.单双层数的起始放置点是不同的， 2.大量的操作是重复的
#作者：杜祥
#date：2020.7.23

#attention:1.数字表示从上至下盘子的层数。 2.ABC分别表示从左到右三根柱子

#移动盘子N的位置
def Move(pillar1,pillar2):
    pillar2.insert(1, pillar1[1])
    pillar1.pop(1)

def deal(N,a,b,c):
    if N==1:    #只有一层的情况单独提出来，作为递归结束的标志
        print("1:{}->{}".format(a[0],c[0]))
        Move(a,c)
        print(a,b,c)
    else:
        deal(N-1,a,b,c)
        if 1 in c:    #这个条件是整个算法的灵魂
            print("{}:{}->{}".format(N,a[0],b[0]))
            Move(a,b)
            print(a, b, c)
            deal(N-1,c,a,b)
        elif 1 in b:
            print("{}:{}->{}".format(N,a[0],c[0]))
            Move(a,c)
            print(a,b,c)
            deal(N-1,b,c,a)
        else:
            print("err!!!")

storey=eval(input("输入汉诺塔的层数："))
a,b,c=["A"],["B"],["C"]     #列表是组合数据类型，可以在函数中使用（这里代表ABC柱子上的盘子）
for i in range(storey):
    a.append(i+1)
if storey%2==1:     #利用单双数决定起始点
    deal(storey,a,b,c)
else:
    deal(storey,a,c,b)
