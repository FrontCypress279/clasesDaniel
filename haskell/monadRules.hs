module monadRules where

funk1 :: [Int] -> [Int]
funk1 xs = xs >>= (\x -> [x * x])
