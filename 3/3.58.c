/**
 * decode2:
 *  subq    %rdx, %rsi
 *  imulq   %rsi, %rdi
 *  movq    %rsi, %rax
 *  salq    $63, %rax
 *  sarq    $63, %rax
 *  xorq    %rdi, %rax
 *  ret
 *  
 *  x in %rdi, y in %rsi, z in %rdx
 */
long decode2(long x, long y, long z)
{
    y = y - z;
    x = x * y;
    return x ^ (y << 63 >> 63);
}