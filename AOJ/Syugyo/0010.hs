main :: IO()
main = do
    n <- read <$> getLine :: Int
    print n