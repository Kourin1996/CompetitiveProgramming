main :: IO ()
main = do
    n <- readLn :: IO Int
    putStrLn $ show $ solve n 100000

solve :: Int -> Int -> Int
solve a b = if a == 0 then b else solve (a-1) (g $ f b)

f :: Int -> Float
f n = (fromIntegral n) * 1.05

g :: Float -> Int
g n =  1000 * ( ceiling (n/1000) )