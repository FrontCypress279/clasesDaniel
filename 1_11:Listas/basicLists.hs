module ListasBasicas where

-- -b +-sqrt(b^2 - 4ac) / 2a
-- si b^2 == 4ac -> 1 solucion
-- si b^2 < 4ac -> 0 solucion
-- si b^2 > 4ac -> 2 solucion

raices :: (Float, Float, Float) -> Maybe (Float, Float)
raices(a, b, c)
        | det == 0 = Just (-b / 2*a, -b / 2*a)
        | det < 0 = Nothing 
        | otherwise = Just ((-b - sqrt det) / 2*a, (-b + sqrt det) / 2*a)
        where det = b^2 - 4*a*c

suma :: Num a => [a] -> a
suma [] = 0
suma (x:xs) = x + suma xs

factores :: Int -> [Int]
factores x = [n | n <- [1..(div x 2)], mod x n == 0]
--factores x = filter (\n -> div x n * n == x) [1..(div x 2)]
--factores x = [n | n <- [1..(div x 2)], div x n * n == x]
--(div a n) * n == a

perfectos :: Int -> [Int]
perfectos x = [n | n <- [6..x], sum (factores n) == n]

abundantes :: Int -> [Int]
abundantes x = [n | n <- [1..x], sum (factores n) > n]

paresNenCirculo :: Int -> Int
paresNenCirculo r = length[(x, y) |
        x <- [0..(pred r)],
        y <- [0..(pred r)],
        x^2 + y^2 < r^2]

--expErr :: Float -> Int
--expErr err = length [aprx | aprx <- map (\m -> (1 + 1/m)**m) [1..],
--        exp 1 - aprx < err]

expErr :: Float -> Int
expErr err = auxErr 1 where
        auxErr m
                | exp 1 - aprx < err = 1
                | otherwise = succ . auxErr $ succ m
                where aprx = (1 + 1/m)**m
