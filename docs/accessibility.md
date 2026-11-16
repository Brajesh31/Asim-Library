# ♿ Documentation accessibility

Although this is a native C++ project rather than a user interface, its documentation and developer experience should remain accessible.

## Documentation practices

- Use descriptive headings and meaningful link text.
- Keep code examples language-labelled and copyable.
- Explain diagrams in adjacent text rather than relying on visuals alone.
- Add useful alt text to meaningful illustrations.
- Do not use colour as the only indicator of a state.
- Keep tables simple and include clear header labels.
- Prefer readable code examples and define domain terms.

## API usability

Exceptions should identify invalid operations by type. Public contracts should explain preconditions, returned values, and complexity. The stream overloads make traversal usable in different output contexts and improve testability.

## Future interfaces

If a GUI, web interface, or visualization is added, keyboard operation, semantic controls, labels, focus visibility, contrast, zoom behavior, and reduced-motion preferences should be included in acceptance criteria.
