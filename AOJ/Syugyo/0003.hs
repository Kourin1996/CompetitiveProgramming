import Control.Monad
import Data.List
{-
main :: IO()
main = do
    n <- readLn :: IO Int
    ll <- replicateM n getLine
    let li = map ((map toInt).words) ll
        la = map (f.(take 3).reverse.sort) li
    putStr $ unlines $ map (\x -> if x then "YES" else "NO") la

toInt :: String -> Int
toInt s = read s :: Int

f :: [Int] -> Bool
f (x:xs) = x*x == (sum $ map (^ 2) xs)
-}

main :: IO ()
main = do
    n <- readLn :: IO Int
    ls <- replicateM n getLine
    putStr $ unlines $ map (\x -> if solve x then "YES" else "NO") ls

solve :: String -> Bool
solve s = x * x + y * y == z * z
    where ns = sort $ map read (words s)
          x  = ns !! 0
          y  = ns !! 1
          z  = ns !! 2