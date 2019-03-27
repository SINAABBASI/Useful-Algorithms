/*
The approach works as follows:

    Denote BLOCK_SIZE = sqrt(N);

    Rearrange all queries in a way we will call “Mo’s order”. It is defined like this: [L1, R1] comes earlier than [L2, R2] in Mo’s order if and only if:
       a) L1⁄BLOCK_SIZE < L2⁄BLOCK_SIZE
       b) L1⁄BLOCK_SIZE == L2⁄BLOCK_SIZE && R1 < R2

    Maintain segment [mo_left, mo_right] for which we know Func([mo_left, mo_right]). Initially, this segment is empty. We set mo_left = 0  and mo_right = -1;

    Answer all queries following Mo’s order. Suppose the next query you want to answer is [L, R]. Then you perform these steps:
       a) while mo_right is less than R, extend current segment to [mo_left, mo_right + 1];
       b) while mo_right is greater than R, cut current segment to [mo_left, mo_right - 1];
       c) while mo_left is greater than L, extend current segment to [mo_left - 1, mo_right];
       d) while mo_left is less than L, cut current segment to [mo_left + 1, mo_right].
    This will take O( (|left - L| + |right - R|) * F) time, because we required that each extension\deletion is performed in O(F) steps. After all transitions, you will have mo_left = L and mo_right = R, which means that you have successfully computed Func([L, R]).
*/