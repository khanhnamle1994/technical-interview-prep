A building has 100 floors. One of the floors is the highest floor an egg can be dropped from without breaking.

If an egg is dropped from above that floor, it will break. If it is dropped from that floor or below, it will be completely undamaged
and you can drop the egg again.

Given two eggs, find the highest floor an egg can be dropped from without breaking, with as few drops as possible.

Solution:
We'll use the first egg to get a range of possible floors that contain the highest floor an egg can be dropped from without breaking. To do this,
we'll drop it from increasingly higher floors until it breaks, skipping some number of floors each time.

When the first egg breaks, we'll use the second egg to find the exact highest floor an egg can be dropped from. We only have to drop the second egg starting from the last floor where the first egg didn't break, up to the floor where the first egg did break. But we have to drop the second egg one floor at a time.

With the first egg, if we skip the same number of floors every time, the worst case number of drops will increase by one every time the first egg doesn't break. To counter this and keep our worst case drops constant, we decrease the number of floors we skip by one each time we drop the first egg.

When we're choosing how many floors to skip the first time we drop the first egg, we know:
1 - We want to skip as few floors as possible, so if the first egg breaks right away we don't have a lot of floors to drop our second egg from.
2 - We always want to be able to reduce the number of floors we're skipping. We don't want to get towards the top and not be able to skip floors any more.

Knowing this, we set up the following equation where nn is the number of floors we skip the first time:
n + (n-1) + (n-2) + \ldots + 1 = 100n+(n−1)+(n−2)+…+1=100

This triangular series ↴ reduces to n * (n+1) / 2 = 100n∗(n+1)/2=100 which solves to give n = 13.651n=13.651. We round up to 14 to be safe. So our first drop will be from the 14th floor, our second will be 13 floors higher on the 27th floor and so on until the first egg breaks. Once it breaks, we'll use the second egg to try every floor starting with the last floor where the first egg didn't break. At worst, we'll drop both eggs a combined total of 14 times.
