#### Algorithm
##### 1 nms:非极大值抑制

详细解释：
根据候选框的类别分类概率做排序：
A<B<C<D<E<F

a):先标记最大概率矩形框F是我们要保留下来的；
b):从最大概率矩形框F开始，分别判断A~E与F的重叠度IOU（两框的交并比）是否大于某个设定的阈值，假设B、D与F的重叠度超过阈值，那么就扔掉B、D；
c):从剩下的矩形框A、C、E中，选择概率最大的E，标记为要保留下来的，然后判读E与A、C的重叠度，扔掉重叠度超过设定阈值的矩形框
