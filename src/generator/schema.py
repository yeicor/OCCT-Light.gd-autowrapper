from typing import Literal

from pydantic import BaseModel, Field


class FunctionArg(BaseModel):
    type: str
    name: str


# LLM-generated output - DO NOT MODIFY
class HandleOut(BaseModel):
    type: Literal["handle"]
    handle_type: str
    doc: str = ""
    condition_directive: Literal["#ifndef", "#ifdef", "#if"] | None = None
    condition_expression: str | None = None


class FunctionOut(BaseModel):
    type: Literal["function"]
    name: str
    return_type: str
    arguments: list[FunctionArg] = Field(default_factory=list)
    body: str = ""
    test_body: str = ""
    doc: str = ""
    extra_headers: list[str] = Field(default_factory=list)
    condition_directive: Literal["#ifndef", "#ifdef", "#if"] | None = None
    condition_expression: str | None = None


class Generate(BaseModel):
    """LLM-generated code items."""

    to_generate: list[HandleOut | FunctionOut] = Field(default_factory=list)


# Enriched versions with programmatic metadata - auto-populated
class HandleOutWithHeader(BaseModel):
    type: Literal["handle"]
    handle_type: str
    doc: str = ""
    header_include: str | None = None
    condition_directive: Literal["#ifndef", "#ifdef", "#if"] | None = None
    condition_expression: str | None = None


class FunctionOutWithClass(BaseModel):
    type: Literal["function"]
    name: str
    return_type: str
    arguments: list[FunctionArg] = Field(default_factory=list)
    body: str = ""
    test_body: str = ""
    doc: str = ""
    extra_headers: list[str] = Field(default_factory=list)
    class_name: str | None = None
    header_include: str | None = None
    condition_directive: Literal["#ifndef", "#ifdef", "#if"] | None = None
    condition_expression: str | None = None


class GenerateWithClass(BaseModel):
    """LLM output enriched with chunk metadata."""

    to_generate: list[HandleOutWithHeader | FunctionOutWithClass] = Field(
        default_factory=list
    )

    @staticmethod
    def from_generate(
        generate: Generate,
        scope: str | None,
        header_include: str | None,
    ) -> "GenerateWithClass":
        """Enrich Generate with chunk metadata to create GenerateWithClass."""
        items = []
        for item in generate.to_generate:
            if isinstance(item, HandleOut):
                items.append(
                    HandleOutWithHeader(
                        type=item.type,
                        handle_type=item.handle_type,
                        doc=item.doc,
                        header_include=header_include,
                        condition_directive=item.condition_directive,
                        condition_expression=item.condition_expression,
                    )
                )
            else:  # FunctionOut
                items.append(
                    FunctionOutWithClass(
                        type=item.type,
                        name=item.name,
                        return_type=item.return_type,
                        arguments=item.arguments,
                        body=item.body,
                        test_body=item.test_body,
                        doc=item.doc,
                        extra_headers=item.extra_headers,
                        class_name=scope,
                        header_include=header_include,
                        condition_directive=item.condition_directive,
                        condition_expression=item.condition_expression,
                    )
                )
        return GenerateWithClass(to_generate=items)
