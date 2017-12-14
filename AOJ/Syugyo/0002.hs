main :: IO()
main = do
    cs <- getContents
    putStr $ unlines $ map (show.f.map read.words) $ lines cs

f :: [Int] -> Int
f = length.show.sum
