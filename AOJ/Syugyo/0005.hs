import Prelude

main :: IO ()
main = do
    c <- getContents
    putStr $ unlines $ map solve $ lines c

solve :: String -> String
solve s = (show (f a b)) ++ " " ++ (show (g a b))
    where l = map read (words s)
          a = l !! 0
          b = l !! 1

f :: Int -> Int -> Int
f a b = if y == 0 then x else f y (mod x y)
    where x = max a b
          y = min a b

g :: Int -> Int -> Int
g a b = div (a*b) (gcd a b)