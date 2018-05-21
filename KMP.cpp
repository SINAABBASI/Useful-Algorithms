function RabinKarp(string s[1..n], string pattern[1..m])

  hpattern := hash(pattern[1..m]);

  for i from 1 to n-m+1

    hs := hash(s[i..i+m-1])

    if hs = hpattern

      if s[i..i+m-1] = pattern[1..m]

        return i

  return not found
// ASCII a = 97, b = 98, r = 114. 
hash("abr") = (97 × 101^2) + (98 × 101^1) + (114 × 101^0) = 999,509 

//             base   old hash    old 'a'         new 'a'
hash("bra") = [101^1 × (999,509 - (97 × 101^2))] + (97 × 101^0) = 1,011,309