import Control.Monad
import Data.List
import Text.Printf

main :: IO ()
main = do
    cs <- getContents
    putStr $ unlines $ map solve (lines cs)

solve :: String -> String
solve s = (floatFormat $ sign x) ++ " " ++ (floatFormat $ sign y)
    where ns = map read (words s)
          a = ns !! 0
          b = ns !! 1
          c = ns !! 2
          d = ns !! 3
          e = ns !! 4
          f = ns !! 5
          x = (e*c-b*f)/(a*e-b*d)
          y = (a*f-d*c)/(a*e-b*d)

sign :: Float -> Float
sign x = if x == 0.0 then 0.0 else x

floatFormat :: Float -> String
floatFormat x = printf "%.3f" x