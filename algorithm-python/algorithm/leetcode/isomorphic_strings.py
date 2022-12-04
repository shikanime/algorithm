class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_vocab = list(dict.fromkeys(s))
        t_vocab = list(dict.fromkeys(t))
        for (cs, ct) in zip(s, t):
            if s_vocab.index(cs) != t_vocab.index(ct):
                return False
        return True
