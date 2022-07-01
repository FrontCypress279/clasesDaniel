module ExampleState where

import          Control.Monad.State (State, evalState, get, mapM, modify, put, runState)

div :: Int -> Maybe Int
div n =
        if n == 0
                then return Nothing
                else return Just n
                
counter :: State Int Int
counter j = do
        i <- get
        put (succ i)
        return (j * i)

main :: IO ()
main = do
        print $evalState (counter 4) 0
