import Control.Monad
import Data.List

main :: IO()
main = do
    hs <- replicateM 10 (readLn :: IO Int)
    let l = take 3 $ reverse $ sort hs
    putStr $ unlines $ map show l
