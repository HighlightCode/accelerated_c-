### Q7: Why doesn't the `max` function use two template parameters, one for each argument type?
The `<` operator between different types are not always supported, so `max` only uses one template parameter to ensure comparison between same types.

### Q8: In the `binary_search` function in §8.2.6, why didn't we write `(begin + end) / 2` instead of the more complicated `begin + (end - begin) / 2`?
If we used `(begin + end) / 2`, `begin + end` would be calculated at first, which may cause the iterators to go out of range of the container.