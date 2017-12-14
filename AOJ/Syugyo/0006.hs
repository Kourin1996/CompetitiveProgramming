main :: IO ()
main = do
    l <- getLine
    putStrLn $ reverse l