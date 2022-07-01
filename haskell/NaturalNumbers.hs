module Naturals where

import   Control.Monad

-- Cero es natural
-- El sucesor de un natural
-- tambien es un natural

data Natural = Zero | S Natural

instance Show Natural where
  show Zero  = "0"
  show (S n) = "S" ++ show n

--
add :: Natural -> Natural -> Natural
add Zero n     = n
add (S n) m = add n (S m)

--Multiplicación
mul :: Natural -> Natural -> Natural
mul Zero _     = Zero
mul (S n) m = (add m . mul n) m
--            add m (mul n m)

--Resta
sub :: Natural -> Natural -> Natural
sub Zero _        = error "negativo"
sub n Zero        = n
sub (S m) (S n) = sub m n

--Menor qué
minor :: Natural -> Natural -> Bool
minor Zero Zero         = False
minor _ Zero            = False
minor Zero _            = True
minor (S m) (S n) = minor m n

--Residuo
res :: Natural -> Natural -> Natural
res m n | minor m n = Zero
        | otherwise = res (sub m n) n

--Cociente (?)
qot :: Natural -> Natural -> Natural
qot m n | minor m n = Zero
        | otherwise = S (qot (sub m n) n)

toPeano :: Int -> Natural
toPeano 0 = Zero
toPeano n | n < 0 = error "Numero negativo"
          | otherwise = (S . toPeano . pred) n
