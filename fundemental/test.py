from typing import Iterable, Callable

float_iterable: Iterable[float] = [3.0, 3.0, 3.0, 4.0, 5.0]



def reduce(
    fn: Callable[[float, float], float], start: float
) -> Callable[[Iterable[float]], float]:
    r"""
    Higher-order reduce.

    Args:
        fn: combine two values
        start: start value $x_0$

    Returns:
         Function that takes a list `ls` of elements
         $x_1 \ldots x_n$ and computes the reduction :math:`fn(x_3, fn(x_2,
         fn(x_1, x_0)))`
    """
    # TODO: Implement for Task 0.3.
    def func(ls: Iterable[float]) -> float:
        result = start
        index = 0
        for item in ls:
            if index != 0:
                result = fn(result, item)
            index += 1
        return result
    return func
    # raise NotImplementedError('Need to implement for Task 0.3')
    
def sum(ls: Iterable[float]) -> float:
    "Sum up a list using `reduce` and `add`."
    # TODO: Implement for Task 0.3.
    return reduce(add, next(iter(ls)))(ls)
    #raise NotImplementedError('Need to implement for Task 0.3')
    
def add(x: float, y: float) -> float:
    "$f(x, y) = x + y$"
    # TODO: Implement for Task 0.1.
    return x + y
    # raise NotImplementedError('Need to implement for Task 0.1')
    
print(sum(float_iterable))

assert sum(float_iterable) == sum(float_iterable)