# Errata for *Beginning C++23*

## Exercise 20-15: format() must be a const member

On **page 828**, the correct outline of the `format()` member is as follows:

```
auto format(const Box& box, std::format_context& context) const
{
    // ...
}
```

In the book the `const` modifier is missing 
(at the time of writing, our compiler was still more forgiving about this mistake).

<!---
***

On **page xx** [Summary of error]:
 
Details of error here. Highlight key pieces in **bold**.

***
-->
